// Making Hot Cocoa

#include <LiquidCrystal.h>                  //the liquid crystal library contains commands for printing to the display
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>                         // Include the servo library:

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 5

// Create a variable to store the servo position:
int angle = 0;

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    // tell the RedBoard what pins are connected to the display

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


void setup() {
  sensors.begin();	                         // Start up the library
  Serial.begin(9600);	                       //* Define baud rate for serial communication */
  lcd.begin(16, 2);                          //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                               //clear the display
  pinMode(RELAY_PIN_PUMP, OUTPUT);           // initialize digital pin 3 as an output.
  pinMode(RELAY_PIN_FAN, OUTPUT);            // initialize digital pin 6 as an output
  pinMode(RELAY_PIN_STIR, OUTPUT);
  myservo.attach(servoPin);                  // Attach the Servo variable to a pin
}

void loop() {
 
  sensors.requestTemperatures();                                 //Send the command to get temperatures
  lcd.setCursor(0, 0);                                           //set cursor to the upper left position
  lcd.print("Degrees F: ");                                      //Print "Degrees F: " 
  lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);    //print the temperature in Fahrenheit
  degreesF = (sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0;    //Make temperature a varible called degreesF
  delay(500);                                                    //wait half a second
  

 

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
     else{
      lcd.setCursor(0, 1);                                     //set the cursor to the upper left position
      lcd.print("STAND BY");                                   //Print that it is waiting for water to heat up
      delay(1000);                                             //wait a full second


    }
 
  }
}
 
