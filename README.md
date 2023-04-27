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

(note all components are rated for 12V, 120V AC)

### Wiring Diagrams

![coco_circuit](coco_circuit.png)

The circuit was used to operate 6 major pieces in the group project cocoa machine these pieces included a thermocouple, LCD screen (controlled by a potentiometer for brightness), servo motor, motor, computer fan, and a pump. The pump, computer fan, motor where all assisted by a 3 prong transistor since the each where powerd by a 12V power source, these transistors where used to feed the components to seperate pins in the arduino board. The process of learning how each component in the circuit operated was a fantastic learning experience, the most difficult learning curve for the group was the understanding of the transistors functionality. The fuinctionality of these transistors allowed us the opportunity to still wire the components to pin fuction on the arduino while also using an outside power source (wall plug-in) to power more intesive components for better functionality of our cocoa machine.

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

```c
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
```

The integers that equal 0 assign tasks that when completed, will equal 1. Constant integers establish the pump, fan, and stirring motor pins respectively. The following code block represents how we printed the degrees on the arduino be reading the temperature from the thermocouple.

```c
void loop() {
 
  sensors.requestTemperatures();                                 //Send the command to get temperatures
  lcd.setCursor(0, 0);                                           //set cursor to the upper left position
  lcd.print("Degrees F: ");                                      //Print "Degrees F: " 
  lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);    //print the temperature in Fahrenheit
  degreesF = (sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0;    //Make temperature a varible called degreesF
  delay(500);              
  ```
  
  If the temperature read was between 80 and 165 degrees Fahrenheit, the LCD screen would display the temperature and that it is brewing. 
 
 ```c
 if (degreesF >= 80 && degreesF < 165){                         //if temp is equal to or above 80 and below 165
    
    lcd.setCursor(0, 0);                                         //set the cursor to the upper left position
    lcd.print("Degrees F: ");                                    //Print a label for the data
    lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);  //print the degrees Fahrenheit

    delay(500);                                                  //wait half a second

    lcd.setCursor(0, 1);                                         //set the cursor to the lower left position
    lcd.print("Heating...");                                     //Print that water is heating
  }
    else if (degreesF >= 165){                                    //if temp is greater than or equal to 165
      lcd.setCursor(0, 0);                                        //set the cursor to the upper left position
      lcd.print("Degrees F: ");                                   //Print a label for the data
      lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0); //print the degrees Fahrenheit

      delay(500);                                                 //wait half a second
```      

Once 165 degrees Fahrenheit is reached, a series of if statements is triggered that will run the brewing process one after another. This includes pumping the water for the cup, dumping powder in, stirring powder out of funnel, and stirring in a sequencial order. At the end, "Done!" will be displayed on the LCD screen to indicate to the user that their hot chocolate is complete. Throughout each if statement, the variable assigned to each task is labeled as 1 to state to the arduino that the task is complete. This was done to ensure that the process does not run again as it is in a loop.

```c
else if (degreesF >= 165){                                    //if temp is greater than or equal to 165
      lcd.setCursor(0, 0);                                        //set the cursor to the upper left position
      lcd.print("Degrees F: ");                                   //Print a label for the data
      lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0); //print the degrees Fahrenheit

      delay(500);                                                 //wait half a second
      
      if (startBrewing == 0){
        lcd.setCursor(0, 1);                                        //set the cursor to the lower left position
       lcd.print("Brewing...");                                    //Print that water is pumping
       delay(500);                                                 //wait half a second
       startBrewing = 1;
      }
      
      
      if (haveIbrewed == 0){
        digitalWrite(RELAY_PIN_PUMP, HIGH);                              // turn on pump 10 seconds
        delay(10000);
        digitalWrite(RELAY_PIN_PUMP, LOW);                               // turn off pump
        haveIbrewed = 1;
        }
      if (haveIdumpedMix == 0){
        myservo.write(90);
        delay(2000);
        myservo.write(0);
        delay(2000);
        haveIdumpedMix = 1;
        }
      if (haveIemptiedMix == 0){
        digitalWrite(RELAY_PIN_STIR, HIGH); // turn on stirrer 10 seconds
        delay(10000);
        digitalWrite(RELAY_PIN_STIR, LOW);  // turn off stirrer
        delay(1000);
        haveIemptiedMix = 1;
      }
      if (haveIstirred == 0){
        analogWrite(RELAY_PIN_FAN, 90); // turn on fan 30 seconds at 90/255 power
        delay(30000);
        analogWrite(RELAY_PIN_FAN, 0);  // turn off fan 
        delay(1000);
        haveIstirred = 1;
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Done!");
        delay(20000);  

    }
    ```
    
    If there is none of the following detected (in other words if the temperature detected is under 80 degrees) it will display "STAND BY" on the LCD screen.
    
    ```c
     else{
      lcd.setCursor(0, 1);                                     //set the cursor to the upper left position
      lcd.print("STAND BY");                                   //Print that it is waiting for water to heat up
      delay(1000);                                             //wait a full second
```

Since the program is stored in the Arduino, the process can be reset by hitting the reset button on the Arduino. This allows for only that button to be pressed to start the process of making hot cocoa without running the code again.

    
  



## Part Analysis

### Project Discussion

## Results
