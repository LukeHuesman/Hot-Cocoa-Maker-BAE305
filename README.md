# Hot-Cocoa-Maker-BAE305
Final project for BAE 305 (TJ Wink, Luke Huesman, and Kate Moore)


![Full_Cocoa_Pic](Full_Cocoa_Pic.jpg)


## Summary

The purpose of this project was to create an automatic hot cocoa maker. All that is required for the user is putting cocoa mix in the funnel and flipping the switch for the water heater after it is filled with water. Once the water is heated to 165 degrees Fahrenheit, it will then pump the water into the cup. This process is followed by dumping the powder in and stirring the mix by using magnets. Overall, the process takes roughly 5 minutes to complete when water is warmed from room temperature. 


## Design Description

### Supplies

- Arduino Uno
- Laptop with capability to run Arduino code
- 12V laptop charger
- LCD screen
- Wires
- Water Pump (self priming, 12V)
- (2) 6 mm silicone tubes
- Electric water kettle
- 3 transistors
- Coffee cup
- 1 Resistor
- BLDC Fan (12V)
- (4) rare earth magnets
- (1) magnetic stirring pill
- 2 servo motors
- Funnel (3D printed for our project)
- Wood for hot cocoa stand
- Potentiometer

(note all components are rated for 12V, ? A)

### Wiring Diagrams

![coco_circuit](coco_circuit.png)

TJ could you talk ab the circuit?

## Test Description

Testing involved troubleshooting the following items:
- LCD screen function
- Thermocouple testing
- Electric kettle function
- Water pump testing
- BLDC fan testing
- Magnet stir testing

#### **LCD screen function**

To test the functionality of the LCD screen, our group ran the "Hello, world!" code given by the Arduino website. This was a simple test to troubleshoot and ensure the LCD screen did not have any malfunction in display. 

#### **Thermocouple testing**

To make sure the thermocouple was detecting temperature properly, our group ran code given by the Arduino website for our specific thermocouple. 

#### **Electric kettle function**



#### **Water pump testing**



#### **BLDC fan testing**



#### **Magnet stir testing**


## Code Overview

Our code was structured to run all of our functions off of one switch. To perform this, our code made a series of if statements, with a function to conduct the brewing process if the temperature reached over 165 degrees Fahrenheit.

Below is our initialized variables, which contain floats and integers

~
float voltage = 0;                          //the voltage measured from the TMP36
float degreesC = 0;                         //the temperature in Celsius, calculated from the voltage
float degreesF = 0;                         //the temperature in Fahrenheit, calculated from the voltage

const int RELAY_PIN_PUMP = 3;                    // the Arduino pin, which connects to the IN pin of relay
const int RELAY_PIN_FAN = 6;                     // the Arduino pin for the fan
const int RELAY_PIN_STIR = 7;                    // the Arduino pin for the stirrer

int haveIbrewed = 0;
int haveIpumpedWater = 0;
int haveIdumpedMix = 0;
int haveIemptiedMix = 0;
int haveIstirred = 0;
int startBrewing = 0;
~

## Part Analysis

### Project Discussion

## Results
