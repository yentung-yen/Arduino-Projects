#include<SPI.h>                                                               //call library
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4                                                          //allows us to define the OLED's status. (Fixed Command)
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);      //to tell the ardruino to turn on the function for the OLED to display any character 

int led1 = 5;


void setup() {                                   //OLED screen use void setup only. void loop is focussed more for other components
  Serial.begin(9600);                            //this serial begin is for the OLED screen (OLED baud rate) because some components need the baud rate to work. Not for the serial monitor.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);     //Address 0x3C for 128x64. For the ardruino to begin to display any character
  display.setTextColor(SSD1306_WHITE);           //Determines colour of text
  display.setTextSize(1);                        //Determines text size (got size 1-8)
  display.clearDisplay();                        //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
  display.setCursor(0,6);                        //starting coordinate for the first character
  display.println("Arduino");                    //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "Arduino"
  display.setTextSize(2);                        //text size
  display.setCursor(0,15);                       //starting coordinate for the second character
  display.println("2021");                       //print(L)n -> lawn(ln), not print(I)n, or print(1 "one")n. Prints text "2021"
  display.display();                             //to tell the arduino to tell the OLED screen to display what we have written
  
  delay(4000);                                   //displays the above text for 4 seconds,
  display.clearDisplay();                        //then clears the display

  pinMode(led1, OUTPUT);
}


void loop() {
  display.clearDisplay();                        //clears the display
  digitalWrite(led1, HIGH);                      //ON's the LED
  display.setTextSize(1);                        //(text size)
  display.setCursor(0,0);                        //(starting coordinate for the text)
  display.println("LED is ON");                  //and prints this at the same time the LED is ON
  display.display();                             //(to tell the arduino to tell the OLED screen to display what we have written)
  delay(2000);                                   //displays the above text for 2 seconds
  
  display.clearDisplay();                        //clears the display
  digitalWrite(led1, LOW);                       //OFF's the LED
  display.setTextSize(1);                        //(text size)
  display.setCursor(0,0);                        //(starting coordinate for the text)
  display.println("LED is OFF");                 //and prints this at the same time the LED is ON 
  display.display();                             //(to tell the arduino to tell the OLED screen to display what we have written)
  delay(2000);                                   //displays the above text for 2 seconds
}

  //ON 1 LED at the same time words are displayed on OLED screen 
