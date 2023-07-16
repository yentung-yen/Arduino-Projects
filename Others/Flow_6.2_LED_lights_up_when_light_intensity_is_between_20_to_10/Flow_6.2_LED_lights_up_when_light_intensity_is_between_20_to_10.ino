#include<SPI.h>                                                               //call libraries
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4                                                          //allows us to define the OLED's status. (Fixed Command)
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);      //to tell the ardruino to turn on the function for the OLED to display any character

int photoresistor = A0;
int led1 = 5;
int sensorvalue = 0;


void setup() {                                      //OLED screen use void setup only. void loop is focussed more for other components
  Serial.begin(9600);                               //this serial begin is for the OLED screen (OLED baud rate) because some components need the baud rate to work. Not for the serial monitor.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);        //Address 0x3C for 128x64. For the ardruino to begin to display any character
  display.setTextColor(SSD1306_WHITE);              //Determines colour of text
  display.setTextSize(1);                           //Determines text size (got size 1-8)
  display.setCursor(0,0);                           //starting coordinate for the first character
  display.clearDisplay();                           //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)

  pinMode(led1, OUTPUT);
  pinMode(photoresistor, INPUT);
}


void loop() {
  sensorvalue = analogRead(photoresistor);          //reads the value from the sensor

  if(sensorvalue > 20 && sensorvalue < 100){        //if sensorvalue is 21 to 99
    digitalWrite(led1, HIGH);                       //ON the LED
    display.clearDisplay();                         //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
    display.setCursor(0,20);                        //starting coordinate for the character
    display.setTextSize(1);                         //Determines text size (got size 1-8)
    display.print("Too bright");                    //Prints this text onto OLED screen
    display.display();                              //Displays the text in the OLED screen
  }
  else{                                             //else, if sensor value is other than 21 to 99
    digitalWrite(led1, LOW);                        //LED is OFF
    display.clearDisplay();                         //Clears everything on the OLED screen
    display.setCursor(0,20);                        //starting coordinate for the character
    display.setTextSize(1);                         //Determines text size (got size 1-8)
    display.print("Not too bright");                //Prints this text onto OLED screen
    display.display();                              //Displays the text in the OLED screen
  }
  delay(500);                                       //delay of 0.5 seconds for ease of viewing 
}

   // display word on OLED screen
   // led lights up when light intensity is above 20 and below 100, and OFF's otherwise
   // teacher's flow
