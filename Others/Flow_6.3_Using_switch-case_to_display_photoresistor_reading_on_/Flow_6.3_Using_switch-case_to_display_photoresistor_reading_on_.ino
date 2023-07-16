#include<SPI.h>                                                               //call libraries
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4                                                          //allows us to define the OLED's status. (Fixed Command)
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);      //to tell the ardruino to turn on the function for the OLED to display any character

int photoresistor = A0;
int led1 = 5;
int led2 = 4;
int sensorvalue = 0;


void setup() {                                      //OLED screen use void setup only. void loop is focussed more for other components
  Serial.begin(9600);                               //this serial begin is for the OLED screen (OLED baud rate) because some components need the baud rate to work. Not for the serial monitor.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);        //Address 0x3C for 128x64. For the ardruino to begin to display any character
  display.setTextColor(SSD1306_WHITE);              //Determines colour of text
  display.setTextSize(1);                           //Determines text size (got size 1-8)
  display.setCursor(0,0);                           //starting coordinate for the first character
  display.clearDisplay();                           //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(photoresistor, INPUT);
}


void loop() {
  sensorvalue = analogRead(photoresistor);          //reads the value from the sensor and save it under "sensorvalue"

  switch(sensorvalue){

    case 0 ... 15:                                  //in the case the sensorvalue is lesser than or equal to 15
    digitalWrite(led2, HIGH);                       //led 2 will turn ON
    delay(500);
    digitalWrite(led2, LOW);
    display.clearDisplay();                         //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,20);                        //set coordinates for the text
    display.setTextSize(1);                         //determine text size (got 1-8)
    display.print("Light Intensity 2:");            //Prints this text onto OLED screen
    display.println(sensorvalue);                   //Prints the value kept in "sensorvalue"
    display.setCursor(100,20);                      //starting coordinate for "sensorvalue"
    break;                                          //exits this particular case

    default:                                        //in default mode (meaning, other than the above case), 
    digitalWrite(led1, HIGH);                       //led 1 should be turned ON
    delay(500);
    digitalWrite(led1, LOW);
    display.clearDisplay();                         //Clears everything on the OLED screen
    display.setCursor(0,20);                        //set coordinates for the text
    display.setTextSize(1);                         //determine text size (got 1-8)
    display.print("Light Intensity 1:");            //Prints this text onto OLED screen
    display.println(sensorvalue);                   //Prints the value kept in "sensorvalue"
    display.setCursor(100,20);                      //starting coordinate for "sensorvalue"
    break;                                          //exits this particular case
  }
  
  display.display();                                //displays the words and numbers on the OLED screen
  delay(500);                                       //delay of 0.5 seconds for ease of viewing 
}

   // display photoresistor reading on OLED screen
   // led 1 lights up when light intensity is above 20 and below 100
   // led 2 lights up otherwise
   // my own flow



   //switch (var) {
   //  case 1(label 1):
         //do something when var equals 1
   //    break;
   //  case 2(label 2):
         //do something when var equals 2
   //    break;
   //  default:
         // if nothing else matches, do the default
         // default is optional
   //    break;

   // Parameters:
   // var - a variable whose value we want to compare with various cases. Allowed data types: integer, characters.
   // label 1, label 2 - constants. Allowed data types: integer, characters.
