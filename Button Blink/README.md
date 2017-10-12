# Button Blink
Implemented on the following processors:
1. MSP430G2553
2. MSP430F5529
3. MSP430FR2311
4. MSP430FR5994
5. MSP430FR6989


## Overall structure of code
The following list gives an idea of the overall structure of the code used to implement Button Blink.

1. Stop WatchDog Timer
2. Initialise Registers (1 button, 1 LED)
3. Poll for button press (button held down) 
3a. While button is held down, force LED off
3b. When button is not held down, force LED on

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

#### Button
At this point, we are begginning to use the buttons that are available on the MSP's. All of the boards have varying
numbers of buttons, each of which are accessed in essentially the same way. In order to access the buttons,
we need to take these 3 actions (order is irrelevant)
* Initialise the button to high
* Set the Button to output
* Enable the pull up resistor for the button

There are two key differences in accessing buttons that we must look at:
1. Initialising the Button to high
2. Enabling the pull up resistor on the button

In order to understand why we need to do both of these things, we can look at the image below:

![alt text](https://imgur.com/a/gudhj "Circuit Diagram detailing why we need a pull-up resistor")

The button is naturally high, as can be seen in the preceeding image. When the switch is open, the voltage on the pin
is Vcc. But when the button is pressed (switch is closed) the voltage on the pin essentially becomes 0, as all of the current will
flow down to ground. Since the button is high when it is not pressed, we must initialise it to a high value.

The pull-up resistor is placed so that high amounts of current do not flow from Vcc to the MCU. If this were to happen, 
our MCU would not have a very good day.

