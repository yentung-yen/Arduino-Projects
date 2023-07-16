#include<SPI.h>                                                               //call library
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_RESET 4                                                          //allows us to define the OLED's status. (Fixed Command)
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, OLED_RESET);      //function to the the ardruino to 

int led1 = 5;
int button = 3;
int buttonstatus = 0; 


void setup() {                                   //OLED screen use void setup only. void loop is focussed more for other components
  Serial.begin(9600);                            //this serial begin is for the OLED screen (OLED baud rate) because some components need the baud rate to work. Not for the serial monitor.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);     //Address 0x3C for 128x64. For the ardruino to begin to display any character
  display.setTextColor(SSD1306_WHITE);           //Determines colour of text
  display.setTextSize(1);                        //Determines text size (got size 1-8)
  display.clearDisplay();                        //Clears everything on the OLED screen. Commonly used before we start writing anything.(Put first at the beginning of the coding)
  
  pinMode(led1, OUTPUT);
  pinMode(button, INPUT);
}


void loop() {
  buttonstatus = digitalRead(button);              //The value on pin 5 is read, and the result/reading will be saved under "buttonstatus".
                                                   //HIGH means 5 volts, and LOW means 0 volts.
  if(buttonstatus == HIGH){  
    display.clearDisplay();                        //clears the display
    digitalWrite(led1, HIGH);                      //ON's LED
    display.setTextSize(1);                        //(text size)
    display.setCursor(0,0);                        //(starting coordinate for the text)
    display.println("LED is ON");                  //and prints this at the same time the LED is ON
    display.display();                             //(to tell the arduino to tell the OLED screen to display what we have written)
    delay(2000);                                
  }
  else{  
    display.clearDisplay();                        //clears the display
    digitalWrite(led1, LOW);                       //OFF's LED
    display.setTextSize(1);                        //(text size)
    display.setCursor(0,0);                        //(starting coordinate for the text)
    display.println("LED is OFF");                 //and prints this at the same time the LED is OFF
    display.display();                             //(to tell the arduino to tell the OLED screen to display what we have written)
    delay(2000);                                   
}
}

   // LED ON's and OLED screen displays text for 2 seconds when button is pressed, then OFF's
   // This repeats again if the button is pressed
