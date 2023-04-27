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